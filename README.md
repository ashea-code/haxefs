## HaxeFS - PhysicsFS Bindings for Haxe

I've known about PhysicsFS for a while now but I never made the connection in my brain to actually integrate it into Haxe.

So I did.

UPDATE: I decided to try and make this a [linc](http://snowkit.github.io/linc/) library. Not official yet, but trying this new structure!

---

### Pre-Release

Really. This is not in a state I would call "stable", "safe", or "good."

Please make pull requests and improve my messy code! Most of this project is being done during my spare time at college, so I don't have all the time I would like to clean things up.

If you want to test this out: `haxelib git haxefs https://github.com/AaronShea/haxefs.git`

### What's PhysicsFS?

The [Official Site](https://icculus.org/physfs/) is better at explaining that than me.

In short, it's a hardware abstraction for your application. You can mount folders and archive files into a virtual UNIX file system like structure. For example, I can mount `blah.zip` as `/assets/images` and access them by finding the file I want in `/assets/images`.

### Why?

I found that OpenFL embedding was not able to handle large files, and I didn't want to have all the assets (images, sounds, etc.) required for my game to be laying out in the open. You can even apply some encryption to the archives if you like, you just may need to modify PhysicsFS a bit. I can pack everything into one or more zip or LZMA archive files and "mount" them into the structure. Then I can easily access the assets without worrying about the compression or underlying archive structure.

### Docs

TODO - this library is nowhere close to done yet!
