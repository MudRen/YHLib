inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
�������ٲ��Ϸ�һ��խխ��ɽ������Ȼ��ɡ�ʯ�������˹�
���һ�����ݡ����϶��˼���ľ׮�����ϴֳ���������Ϊ���֡�
�ٲ��ڽ��±��ڶ������ڲ�Զ��ɽ���»��һ����̶��
LONG );
	set("exits", ([
		"southdown" : __DIR__"shijie5",
		"northup" : __DIR__"shijie7",
	]));
        set("objects",([
                CLASS_D("shaolin") + "/jue-yuan" : 1,
        ]));

	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}

