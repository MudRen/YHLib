inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
�ٵ��Ե�һ��С·����Ϊƽʱ����֮�˲����Ե�ʣ���Χ��
�ѳ������Ӳݡ�ԶԶ��������ȥ���ƺ���һ����լ��
LONG);
	set("exits", ([
		"west"  : __DIR__"shang_road2",
		"north"  : __DIR__"shang_men",
	]));
	set("outdoors", "ruzhou");
	setup();
	replace_program(ROOM);
}
