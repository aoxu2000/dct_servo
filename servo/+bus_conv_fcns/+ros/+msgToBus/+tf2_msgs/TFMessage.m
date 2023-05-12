function slBusOut = TFMessage(msgIn, slBusOut, varargin)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    maxlength = length(slBusOut.Transforms);
    recvdlength = length(msgIn.Transforms);
    currentlength = min(maxlength, recvdlength);
    if (max(recvdlength) > maxlength) && ...
            isequal(varargin{1}{1},ros.slros.internal.bus.VarLenArrayTruncationAction.EmitWarning)
        diag = MSLDiagnostic([], ...
                             message('ros:slros:busconvert:TruncatedArray', ...
                                     'Transforms', msgIn.MessageType, maxlength, max(recvdlength), maxlength, varargin{2}));
        reportAsWarning(diag);
    end
    slBusOut.Transforms_SL_Info.ReceivedLength = uint32(recvdlength);
    slBusOut.Transforms_SL_Info.CurrentLength = uint32(currentlength);
    for iter=1:currentlength
        slBusOut.Transforms(iter) = bus_conv_fcns.ros.msgToBus.geometry_msgs.TransformStamped(msgIn.Transforms(iter),slBusOut(1).Transforms(iter),varargin{:});
    end
end
