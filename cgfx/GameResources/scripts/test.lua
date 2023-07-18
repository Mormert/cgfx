test = {}

-- some other this text will be seen in the editor now

function test.setup()
    obj = {}
    obj.somevar = "somehello string"
    obj.counter = 0
    LOGE("setup")
    return obj
end


function test.start(self)
    LOGE("start")
end


function test.update(self, dt)
    self.counter = self.counter + 1
    if (self.counter % 60 == 0) then
		LOGE(tostring(self.counter))
		asd = self.object.transform
		--bbbb = asd:loca2lPos()
        LOGE(tostring(asd))
   		--LOGE(tostring(self.object:transform():localPos().x))

    end

    self.object.name = "yo  " .. tostring(self.counter)
end

function test.onDestroy(self)
    LOGE(self.somevar .. "yo yo yo hahahahah byhe bye")
end










