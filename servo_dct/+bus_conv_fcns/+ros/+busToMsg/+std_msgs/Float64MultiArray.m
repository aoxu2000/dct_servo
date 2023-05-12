function rosmsgOut = Float64MultiArray(slBusIn, rosmsgOut)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    rosmsgOut.Layout = bus_conv_fcns.ros.busToMsg.std_msgs.MultiArrayLayout(slBusIn.Layout,rosmsgOut.Layout(1));
    rosmsgOut.Data = double(slBusIn.Data(1:slBusIn.Data_SL_Info.CurrentLength));
end
