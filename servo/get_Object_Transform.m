function [res, T] = get_Object_Transform(vrep, clientID, MotorHandle_Target, MotorHandle_Base)
%% 获取MotorHandle_Target相对于MotorHandle_Base的变换矩阵
[res_1, p] = vrep.simxGetObjectPosition(clientID, MotorHandle_Target, MotorHandle_Base,vrep.simx_opmode_blocking ); % simx_opmode_buffer  simx_opmode_streaming
[res_2, eulerAngles] = vrep.simxGetObjectOrientation(clientID, MotorHandle_Target, MotorHandle_Base,vrep.simx_opmode_blocking );% simx_opmode_buffer  simx_opmode_streaming
res = res_1 + res_2;
if res == 0
    eulerAngles_deg = rad2deg( double(eulerAngles) );
    p = double(p');
    if eulerAngles_deg(3) > 10000
        fprintf('eulerAngles_deg(3)错误');
    end
    R = rotx(eulerAngles_deg(1)) * roty(eulerAngles_deg(2)) * rotz(eulerAngles_deg(3));
    T = RpToTrans(R, p);
else
    T = eye(4);
end
end