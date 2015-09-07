import haxefs.HaxeFS;

class Test 
{

	private static var helloWorldBytes:Array<Int> = [72,101,108,108,111,32,87,111,114,108,100,33];

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