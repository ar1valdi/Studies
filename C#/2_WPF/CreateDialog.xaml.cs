using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace lab8
{
    /// <summary>
    /// Logika interakcji dla klasy CreateDialog.xaml
    /// </summary>
    public partial class CreateDialog : Window
    {
        string parentPath;
        MainWindow mainWindow;

        public CreateDialog(string parentPath, MainWindow mainWindow)
        {
            this.parentPath = parentPath;
            this.mainWindow = mainWindow;
            InitializeComponent();
        }

        private void OnOkClick(object sender, RoutedEventArgs e)
        {
            string filename = TextBoxFilename.Text;
            if (!IsValidFileName(filename, RadioFile.IsChecked == true))
            {
                MessageBox.Show("Invalid filename!");
                return;
            }
            
            FileAttributes atr = FileAttributes.Normal;
            if (CheckboxReadOnly.IsChecked == true)
            {
                atr |= FileAttributes.ReadOnly;
            }
            if (CheckboxArchive.IsChecked == true)
            {
                atr |= FileAttributes.Archive;
            }
            if (CheckboxHidden.IsChecked == true)
            {
                atr |= FileAttributes.Hidden;
            }
            if (CheckboxSystem.IsChecked == true)
            {
                atr |= FileAttributes.System;
            }

            string finalPath = parentPath + "\\" + filename;
            MessageBox.Show(finalPath);
            if (RadioFile.IsChecked == true)
            {
                if (File.Exists(finalPath))
                {
                    MessageBox.Show("File already exists");
                }
                else
                {
                    FileStream fs = File.Create(finalPath);
                    fs.Close();
                    File.SetAttributes(finalPath, atr);
                }
            }
            else
            {
                if (Directory.Exists(finalPath))
                {
                    MessageBox.Show("File already exists");
                }
                else
                {
                    Directory.CreateDirectory(finalPath);
                }
            }

            mainWindow.RefreshWithLastOpened();
            Close();
        }

        private void OnCancelClick(object sender, RoutedEventArgs e)
        {
            Close();
        }

        private bool IsValidFileName(string fileName, bool isFile)
        {
            string pattern = "";
            if (isFile)
            {
                pattern = @"^[a-zA-Z0-9_~-]{1,8}\.(txt|php|html)$";
            }
            else
            {
                pattern = @"^[a-zA-Z0-9_~-]{1,8}$";
            }
            return Regex.IsMatch(fileName, pattern);
        }
    }
}
