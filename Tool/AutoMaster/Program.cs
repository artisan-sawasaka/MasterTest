using System;
using System.Collections.Generic;
using System.Linq;

namespace AutoMaster
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 3)
            {
                return;
            }

            var infos = Excel.Load(new string[] { args[0] });
            foreach (var info in infos)
            {
                info.OutputSource(args[1]);
                info.OutputBinary(args[2]);
            }
        }
    }
}
