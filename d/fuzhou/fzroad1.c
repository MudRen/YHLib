inherit ROOM;

void create()
{
	set("short", "��ϼ��");
	set("long", @LONG
������������ˮ����ϼ�롣���������������дУ�����
�˳�������β�ɡ���;��ɽ·ʮ�����У������Ŀ���Ҳ������
��������Խ��Խ���Ա�ʶ�ˡ�
LONG);
	set("exits", ([
                "northdown" : "/d/quanzhou/qzroad4",
                "south"     : __DIR__"erbapu",
	]));
        set("objects", ([
                "/clone/quarry/tu" : 2,
	]));
	set("outdoors", "fuzhou");
	setup();
	replace_program(ROOM);
}

