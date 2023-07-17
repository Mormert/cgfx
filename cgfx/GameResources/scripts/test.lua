test = {}

function test.setup()
    obj = {}
    obj.somevar = "somehello string"
    obj.counter = 0
    LOGE("setup")
    return obj
end

function test.start(self)
    LOGE("start")

    LOGE(self.somevar .. "star t sssss asass")
end

function test.update(self, dt)
    self.counter = self.counter + 1
    if (self.counter % 12 == 0) then
        LOGE(tostring(self.counter))
    end
end

function test.onDestroy(self)
    LOGE(self.somevar .. "yo yo yo hahahahah byhe bye")
end










