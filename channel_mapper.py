class ChannelMapper:

    def __init__(self):
        self.channel_map = {"CBC": "1",
                            "CTV": "2"}

    def get_channel_address_by_name(self, name):
        if name in self.channel_map:
           return self.channel_map[name];
