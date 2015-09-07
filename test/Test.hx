import haxefs.HaxeFS;

class Test 
{
	static function main()
	{

		trace('Init PhysFS');
		HaxeFS.init();
		test("../test.zip");
		test("../dir");

	}

	static function test(mntPath:String)
	{
		trace("Test mount - " + mntPath);
		if(!HaxeFS.mnt(mntPath, "test", true))
		{
			throw "Could not mount '" + mntPath + "'";
		}

		trace("Test Read bytes from 'file'");
		trace(HaxeFS.read('/test/file'));

		trace("Test unmount - " + mntPath);
		if(!HaxeFS.umnt(mntPath))
		{
			throw "Could not unmount '" + mntPath + "'";
		}
	}
}