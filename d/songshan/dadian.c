inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
��������ż䣬������䣬�����е�ʽ�ݶ����������߳�
�ߵ�̨���ϣ�������ΰ������й���������������
LONG );
	set("exits", ([
		"northup" : __DIR__"shandao1",
		"south"   : __DIR__"chongsheng",
	]));
	set("no_clean_up", 0);
        set("objects", ([
                CLASS_D("songshan") + "/di" : 1,
        ])); 
	setup();
	replace_program(ROOM);
}

