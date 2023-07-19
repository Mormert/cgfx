test = {}

-- some other this text will be seen in the editor now

function test.update(self, dt)

    local testVec3 = vec3.new(1,-20,1)
    testVec3 = testVec3 / 3
    self.object:transform():setWorldPos(testVec3)




    self.counter = self.counter + 1
    if (self.counter % 60 == 0) then

        m4 = self.object:transform():worldMatrix()
        vecFromMat = m4
       -- m4 = mat4.inverse(m4)
        --LOGE(tostring(m4))
        m4:set(1, vec4.new(2))
        --LOGE(tostring(m4:get(1).y))
        local vecsoo = vec2.new(1,2):length()
        LOGF("vecsoo " .. tostring(vecsoo))

        p = vec4.new(5)
        s = vec4.new(p) * 2
        t = vec4.mix(s,p,0.5);
        --LOGW(tostring(t))

        testVec3 = vec3.new(3,2.525,1.2) * vec3.new(5,2,5)
       -- LOGE(tostring(testVec3))
    
        local idx = self.counter % 10 + 1
        self.object:transform():setWorldPos(self.points[idx])

    end

    --self.object.name = "yo  " .. tostring(self.counter)
end

function test.setup()
    obj = {}
    obj.somevar = "somehello string"
    obj.counter = 0

    obj.points = {}
    for i = 1, 10 do
        local v = vec3.new()
        v.x = math.random(-10,10)
        v.y = math.random(-30,-20)
        v.z = math.random(-10,10)
        obj.points[i] = v
    end

    LOGE("setup")
    return obj
end


function test.start(self)
    LOGE("start")
end




function test.onDestroy(self)
    LOGE(self.somevar .. "yo yo yo hahahahah byhe bye")
end

