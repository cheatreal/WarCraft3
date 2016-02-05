using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Threading;
using System.Windows.Threading;

namespace NRD
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window
    {
        Thread t;
        Process pl = new Process();

        public MainWindow()
        {
            InitializeComponent();
            this.MouseLeftButtonDown += new MouseButtonEventHandler(Window1_MouseLeftButtonDown);
            Storyboard sb = (Storyboard)FindResource("startProgressRingStoryBoard");
            sb.Begin();
            t = new Thread(initProcess);
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
                    tbpercent.Text = "Find!";
                }));

                sb.Remove();
                t.Abort();

            }

        }

        void Window1_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            DragMove();
        }
        
    }

    public class Process
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

}
            