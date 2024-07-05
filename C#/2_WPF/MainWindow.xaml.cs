using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.IO;
using System.Xml.Linq;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.TextBox;

namespace lab8
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        string currPath = "";

        public MainWindow()
        {
            InitializeComponent();
        }

        private void OnOpenClicked(object sender, RoutedEventArgs e)
        {
            var dlg = new System.Windows.Forms.FolderBrowserDialog() { Description = "Select directory to open" };
            System.Windows.Forms.DialogResult result = dlg.ShowDialog();
            if (result == System.Windows.Forms.DialogResult.OK)
            {
                fileTreeView.Items.Clear();
                BuildFileTreeView(dlg.SelectedPath);
                currPath = dlg.SelectedPath;
            }
        }

        private void OnExitClicked(object sender, RoutedEventArgs e)
        {
            Close();
        }

        private void BuildFileTreeView(string path)
        {
            var root = new TreeViewItem
            {
                Header = System.IO.Path.GetFileName(path),
                Tag = path
            };
            root.ContextMenu = CreateContextMenu(!Directory.Exists(path));
            fileTreeView.Items.Add(root);
            PopulateFileTreeItems(path, root);
        }

        private void PopulateFileTreeItems(string path, TreeViewItem parent)
        {
            foreach (string subdir in Directory.GetDirectories(path))
            {
                var newItem = new TreeViewItem
                {
                    Header = System.IO.Path.GetFileName(subdir),
                    Tag = subdir
                };
                newItem.ContextMenu = CreateContextMenu(false);
                parent.Items.Add(newItem);
                PopulateFileTreeItems(subdir, newItem);
            }

            foreach (string file in Directory.GetFiles(path))
            {
                var newItem = new TreeViewItem
                {
                    Header = System.IO.Path.GetFileName(file),
                    Tag = file
                };
                newItem.ContextMenu = CreateContextMenu(true);
                parent.Items.Add(newItem);
            }
        }

        private ContextMenu CreateContextMenu(bool isFile)
        {
            var contextMenu = new ContextMenu();

            var delete = new MenuItem();
            delete.Header = "Delete";
            delete.Click += OnDeleteClicked;
            var option2 = new MenuItem();
            if (isFile)
            {
                option2.Header = "Open";
                option2.Click += OnOpenFileClicked;
            } 
            else 
            {
                option2.Header = "Create";
                option2.Click += OnCreateClicked;
            }
            contextMenu.Items.Add(option2);
            contextMenu.Items.Add(delete);
            return contextMenu;
        }

        private void OnOpenFileClicked(object sender, RoutedEventArgs e)
        {
            TreeViewItem selected = (TreeViewItem)fileTreeView.SelectedItem;
            if (selected == null) { return; }
            string path = (string)selected.Tag;

            if (File.Exists(path))
            {
                FileContent.Text = File.ReadAllText(path);
            }
        }

        private void OnCreateClicked(object sender, RoutedEventArgs e)
        {
            TreeViewItem selected = (TreeViewItem)fileTreeView.SelectedItem;
            if (selected == null) { return; }
            string path = (string)selected.Tag;

            CreateDialog createDialog = new CreateDialog(path, this);
            createDialog.Show();
        }

        private void OnDeleteClicked(object sender, RoutedEventArgs e)
        {
            TreeViewItem selected = (TreeViewItem)fileTreeView.SelectedItem;
            if (selected == null) { return; }
            string path = (string)selected.Tag;
            DeleteObject(path);
            TreeViewItem parent = (TreeViewItem)selected.Parent;
            parent.Items.Remove(selected);
        }

        private void DeleteObject(string path)
        {
            File.SetAttributes(path, FileAttributes.Normal);

            if (Directory.Exists(path))
            {
                foreach (string subdir in Directory.GetDirectories(path))
                {
                    DeleteObject(subdir);
                }

                foreach (string file in Directory.GetFiles(path))
                {
                    DeleteObject(file);
                }

                Directory.Delete(path, false);
            }
            else if (File.Exists(path))
            {
                File.Delete(path);
            }
        }

        private void UpdateStatusBarText(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            TreeViewItem selected = (TreeViewItem)fileTreeView.SelectedItem;
            if (selected == null) { return; }
            FileAttributes atrs = GetFileAttributes((string)selected.Tag);
            statusText.Text = GetFileAttributesString(atrs);
        }

        private FileAttributes GetFileAttributes(string path)
        {
            if (File.Exists(path))
            {
                return File.GetAttributes(path);
            }
            else
            {
                return (new DirectoryInfo(path)).Attributes;
            }
        }

        private string GetFileAttributesString(FileAttributes attributes)
        {
            char[] res = { '-', '-', '-', '-' };

            if ((attributes & FileAttributes.ReadOnly) == FileAttributes.ReadOnly)
            {
                res[0] = 'r';
            }

            if ((attributes & FileAttributes.Archive) == FileAttributes.Archive)
            {
                res[1] = 'a';
            }

            if ((attributes & FileAttributes.System) == FileAttributes.System)
            {
                res[2] = 's';
            }

            if ((attributes & FileAttributes.Hidden) == FileAttributes.Hidden)
            {
                res[3] = 'h';
            }

            return new string(res);
        }

        public void RefreshWithLastOpened()
        {
            fileTreeView.Items.Clear();
            if (Directory.Exists(currPath))
            {
                BuildFileTreeView(currPath);
            }
        }
    }
}
