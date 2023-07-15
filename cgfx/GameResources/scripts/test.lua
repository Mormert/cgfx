LOGE('Martin is a great wizard at physics')

a = 3
b = 5
aplusb = a + b

for i = 1, 10 do
    LOGE(tostring(aplusb * i))
end

require("mobdebug").start()