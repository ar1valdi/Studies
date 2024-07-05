using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab10
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel;

    public class SortableBindingList<T> : BindingList<T>
    {
        private PropertyDescriptor _sortProperty;
        private ListSortDirection _sortDirection;

        public SortableBindingList() : base() { }

        public SortableBindingList(List<T> list) : base(list) { }

        protected override bool SupportsSortingCore => true;
        protected override bool SupportsSearchingCore => true;

        protected override bool IsSortedCore => _sortProperty != null;

        protected override ListSortDirection SortDirectionCore => _sortDirection;

        protected override PropertyDescriptor SortPropertyCore => _sortProperty;

        protected override void ApplySortCore(PropertyDescriptor prop, ListSortDirection direction)
        {
            if (prop.PropertyType.GetInterface("IComparable") == null)
                throw new ArgumentException("Property type must implement IComparable interface.");

            var itemsList = Items as List<T>;
            if (itemsList != null)
            {
                itemsList.Sort((x, y) =>
                {
                    var val1 = prop.GetValue(x) as IComparable;
                    var val2 = prop.GetValue(y) as IComparable;
                    return direction == ListSortDirection.Ascending ?
                        val1.CompareTo(val2) : val2.CompareTo(val1);
                });
                _sortProperty = prop;
                _sortDirection = direction;
                OnListChanged(new ListChangedEventArgs(ListChangedType.Reset, -1));
            }
        }

        public void ApplySort(string propertyName, ListSortDirection direction)
        {
            var prop = TypeDescriptor.GetProperties(typeof(T))[propertyName];
            if (prop == null)
                throw new ArgumentException("Property not found.", nameof(propertyName));
            ApplySortCore(prop, direction);
        }

        public void RemoveSort()
        {
            _sortProperty = null;
            _sortDirection = ListSortDirection.Ascending;
            ApplySortCore(null, ListSortDirection.Ascending);
        }
        public int Find(string propertyName, object key)
        {
            var prop = TypeDescriptor.GetProperties(typeof(T))[propertyName];
            if (prop == null)
                throw new ArgumentException("Property not found.", nameof(propertyName));
            return FindCore(prop, key);
        }

        protected override int FindCore(PropertyDescriptor prop, object key)
        {
            bool hasToBeConverted = false;
            if (prop.PropertyType == typeof(Int32) && key as string != null)
            {
                hasToBeConverted = true;
            }

            if (prop.PropertyType == typeof(string) || prop.PropertyType == typeof(Int32))
            {
                for (int i = 0; i < Count; i++)
                {
                    T item = this[i];
                    var value = prop.GetValue(item);

                    if (hasToBeConverted)
                    {
                        try
                        {
                            if (value.ToString() != null && value.ToString().Equals(key.ToString()))
                            {
                                return i;
                            }
                        }
                        catch (Exception ex) { }
                    }
                    else if (value != null && value.Equals(key))
                    {
                        return i;
                    }
                }
            }
            return -1;
        }
    }
}
