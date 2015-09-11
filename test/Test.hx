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

		trace(" ----- Testing using path: " + mntPath);

		trace("Test mount - " + mntPath);
		if(!HaxeFS.mnt(mntPath, "test", true))
		{
			throw "Could not mount '" + mntPath + "'";
		}

		trace("Test File Exists");
		trace(HaxeFS.exist('/test/file'));
		if(!HaxeFS.exist('/test/file'))
		{
			throw "File should exist: '" + mntPath + "'";
		}

		trace("Test file is directory");
		trace(HaxeFS.isdir('/test/file'));
		if(HaxeFS.isdir('/test/file'))
		{
			throw "File should not be a directory";
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