inherit ROOM;

void create()
{
	set("short", "��ׯ��Ժ");
	set("long", @LONG
���߽���Ժ��ӭ����һ����ɽˮ�أ����ϰ���һ�����ι�
״��ʯͷ����˵�ǵ��껨ʯ�ٵ���ʯ��ˮ�ص����������˻��ݡ�
������һ�û����������дУ��ڸ��˴���Ժ�ӡ�ǰ����һ��
�����ߵ�ͨ����Ժ���м���ؤ����Ӱ��ء�
LONG);
        set("outdoors", "city");
	set("exits", ([
                "east"  : __DIR__"ma_chufang",
		"north" : __DIR__"ma_houyuan",
		"south" : __DIR__"ma_damen",
	]));
        set("objects", ([
                "/d/gaibang/npc/3dai" : 1,
                "/d/gaibang/npc/4dai" : 1,
        ]));
	setup();
	replace_program(ROOM);
}

