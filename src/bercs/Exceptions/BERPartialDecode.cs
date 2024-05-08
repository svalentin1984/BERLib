using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BER.Exceptions
{
    public class BERPartialDecode : Exception
    {

        protected IBaseBERType ber = null;
        public IBaseBERType BER
        {
            get { return ber; }
        }

        public BERPartialDecode(IBaseBERType berObject)
        {
            ber = berObject;
        }

    }
}
