using System;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows;
using System.Windows.Input;
using System.Windows.Media.Animation;
using System.Threading;
using System.Windows.Threading;
using System.Diagnostics;
using WinForms = System.Windows.Forms;

namespace NRD
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window
    {
        Thread t;
        ProcessCheck pl = new ProcessCheck();

        public MainWindow()
        {
            InitializeComponent();
            this.MouseLeftButtonDown += new MouseButtonEventHandler(Window1_MouseLeftButtonDown);
            Storyboard sb = (Storyboard)FindResource("startProgressRingStoryBoard");
            sb.Begin();
            t = new Thread(initProcess);
            t.IsBackground = true;
            t.Start();

        }
        
        void initProcess()
        {
            Storyboard sb = (Storyboard)FindResource("startProgressRingStoryBoard");

            if (pl.checkProcess())
            {
                Dispatcher.Invoke(DispatcherPriority.Normal, new Action(() => {
                    Storyboard sb2 = (Storyboard)FindResource("endProgressRingStoryBoard");
                    sb2.Begin();
                    sb.Remove();
                    tbpercent.Text = "Find!";
                }));
                Thread.Sleep(3000);
                Injector inject = new Injector();
                Process proc = Process.GetProcessesByName("war3")[0];
                string dllPath = AppDomain.CurrentDomain.BaseDirectory +"NRD.dll";
                inject.inject(dllPath, proc);
                t.Abort();
                
            }

        }

        void Window1_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            DragMove();
        }

        private void makerClick(object sender, RoutedEventArgs e)
        {
            Process.Start("http://blog.naver.com/cheatreal");
        }

        private void exitClick(object sender, RoutedEventArgs e)
        {
            Environment.Exit(0);
        }
        
    }

    public class ProcessCheck
    {
        public bool checkProcess()
        {
            while (true)
            {
                System.Diagnostics.Process[] myProcesses = System.Diagnostics.Process.GetProcesses();
                for (int i = 0; i < myProcesses.Length; i++)
                {
                    if( myProcesses[i].ProcessName == "war3")
                    {
                        return true;
                    }
                }
            }
            
        }
    }

    public class Injector
    {
        [DllImport("kernel32.dll")]
        public static extern IntPtr OpenProcess(int dwDesiredAccess, bool bInheritHandle, int dwProcessId);

        [DllImport("kernel32.dll", CharSet = CharSet.Auto)]
        public static extern IntPtr GetModuleHandle(string lpModuleName);

        [DllImport("kernel32", CharSet = CharSet.Ansi, ExactSpelling = true, SetLastError = true)]
        static extern IntPtr GetProcAddress(IntPtr hModule, string procName);

        [DllImport("kernel32.dll", SetLastError = true, ExactSpelling = true)]
        static extern IntPtr VirtualAllocEx(IntPtr hProcess,
            IntPtr lpAddress,
            uint dwSize,
            uint flAllocationType,
            uint flProtect);

        [DllImport("kernel32.dll", SetLastError = true)]
        static extern bool WriteProcessMemory(IntPtr hProcess,
            IntPtr lpBaseAddress,
            byte[] lpBuffer,
            uint nSize,
            out UIntPtr lpNumberOfBytesWritten);

        [DllImport("kernel32.dll")]
        static extern IntPtr CreateRemoteThread(IntPtr hProcess,
            IntPtr lpThreadAttributes,
            uint dwStackSize,
            IntPtr lpStartAddress,
            IntPtr lpParameter,
            uint dwCreationFlags,
            IntPtr lpThreadId);

        const uint MEM_COMMIT = 0x00001000;
        const uint MEM_RESERVE = 0x00002000;
        const uint PAGE_READWRITE = 4;
        const int MAXIMUM_ALLOWED = 0x2000000;

        public int inject(string dllPath, Process tProcess)
        {
            Process targetProcess = tProcess;
            string dllName = dllPath;

            IntPtr procHandle = OpenProcess(MAXIMUM_ALLOWED,
                false, targetProcess.Id);

            IntPtr loadLibraryAddr = GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA");

            IntPtr allocMemAddress = VirtualAllocEx(procHandle, IntPtr.Zero, (uint)((dllName.Length + 1) * Marshal.SizeOf(typeof(char))), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

            UIntPtr bytesWritten;
            WriteProcessMemory(procHandle, allocMemAddress, Encoding.Default.GetBytes(dllName), (uint)((dllName.Length + 1) * Marshal.SizeOf(typeof(char))), out bytesWritten);
      
            CreateRemoteThread(procHandle, IntPtr.Zero, 0, loadLibraryAddr, allocMemAddress, 0, IntPtr.Zero);
            return 0;
        }
    }
}

