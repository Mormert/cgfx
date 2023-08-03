test = {}

-- some other this text will be seen in the editor now

lol = { "asd", "asdsad" }

WTFYAO = { "hej", 2, 5 }
WTFYAO["asdasd"] = 1337.2
WTFYAO["dadad"] = { lol, 1338 }
WTFYAO["bbb"] = 631631.3
WTFYAO["blublublublbub"] = jlePath.new("ER:asd/coo")
WTFYAO["blublublubsslbub"] = vec4.new(1.5)
WTFYAO["MADDAFAKASSSS"] = jleObject.new()
WTFYAO["blublublubsslbu33b"] = vec4.new(2.5)


function canBePrinted(item)
    if (pcall(function()
        pairs(item)
    end)) then
    else
        return false
    end
    return true
end

function rPrint(s, l, i)
    -- recursive Print (structure, limit, indent)
    if (s ~= "_G") then
        l = (l) or 100;
        i = i or "";    -- default item limit, indent string
        if (l < 1) then
            print "ERROR: Item limit reached.";
            return l - 1
        end ;
        local ts = type(s);
        if (ts ~= "table") then
            print(i, ts, s);
            return l - 1
        end
        print(i, ts);           -- print "table"
        for k, v in pairs(s) do
            -- print "[KEY] VALUE"
            rPrint(v, l, i .. "\t[" .. tostring(k) .. "]")
            if (l < 0) then
                break
            end
        end
    end
    return l
end


--local inspect = require("inspect")

function test.printTable(item)

    print_table(item)

    --rPrint(WTFYAO)
    --print(inspect(_G))

    --print(DataDumper(WTFYAO))
    --printtable(WTFYAO)

    --[[for k,v in pairs(item) do
        if k~="_G" then
            if type(v)=="string" or type(v)=="number" then
                print("G["..k.."]="..v)
            elseif type(v)=="table" then
                print("G["..k.."]=("..type(v)..")="..string.len(tostring(k)..tostring(v)))
                test.printTable(v)

            else
                print("G["..k.."]=("..type(v)..")")
            end
        end
    end]]
end



function test.update(self, dt)


    self.counter = self.counter + 1
    if (self.counter % 60 == 0) then

        --self.cLight.color.x = 0

        m4 = self.object:transform():worldMatrix()
        vecFromMat = m4
        -- m4 = mat4.inverse(m4)
        -- LOGE(tostring(m4))
        m4:set(1, vec4.new(2))
        -- LOGE(tostring(m4:get(1).y))
        local vecsoo = vec2.new(1, 2):length()
        --LOGF("vecsoo " .. tostring(self.cLight.color))

        p = vec4.new(5)
        s = vec4.new(p) * 2
        t = vec4.mix(s, p, 0.5);
        -- LOGW(tostring(t))

        testVec3 = vec3.new(3, 2.525, 1.2) * vec3.new(5, 2, 5)
        WTFYAO["rofl"] = testVec3
        -- LOGE(tostring(testVec3))

        local idx = self.counter % 10 + 1
        self.object:transform():setWorldPos(self.points[idx])



        --self.object.scene:destroy()

    end

    self.cLight.color = vec3.new(25, 25, 500 * math.sin(self.counter * 0.02) + 800)

    -- self.object.name = "yo  " .. tostring(self.counter)
end

function test.setup()
    local obj = {}
    obj.somevar = "somehello string"
    obj.counter = 0

    obj.points = {}
    for i = 1, 10 do
        local v = vec3.new()
        v.x = math.random(-10, 10)
        v.y = math.random(-40, -30)
        v.z = math.random(-10, 10)
        obj.points[i] = v
    end

    LOGE("setup")
    return obj
end

function test.start(self)

    self.object:addComponent("cLight");
    LOGE("start")
end

function test.onDestroy(self)
    LOGE(self.somevar .. "yo yo yo hahahahah byhe bye")
end

