inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
����һ��������С���ݣ�������Ϊ���ף��˿Ͷ��ǴҴҵ�
���ˣ������ӡ����ȡ��׾ƾ͸�·ȥ�ˡ�
LONG);
	set("exits", ([
		"west" : __DIR__"beidajie2",
       	]));
	set("objects", ([
                "/d/city/npc/xiaoer2" : 1,
	]));

	setup();
	replace_program(ROOM);
}

