inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����������ϱ������������ţ�������ӯ�ţ�����ǰ����
��Ѳʱ���ߵĵ��������޵��Ǹ���ƽ���������ߵ��̲��ϡ���
���ٹ�ȥ��Զ�����ǿ��⸮���á������Ǵ�����¡�
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
		"south" : __DIR__"jiedao1",
		"north" : __DIR__"xianguosi",
	]));
        set("outdoors", "kaifeng");
        set("objects", ([
		__DIR__"npc/fujiazi" : 1,
		__DIR__"npc/qigai" : 1,
	]));

        setup();
        replace_program(ROOM);
}
