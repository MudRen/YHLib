inherit ROOM;

void create()
{
        set("short", "��ӯ��");
        set("long", @LONG
��ӯ���ǿ���ǵ����ţ����ڿ��⸮�������з������⾳
�ں���ƽ�������ǲ�Զ��������̨��
LONG);
        set("objects", ([
  		__DIR__"npc/guanbing" : 2,
                "/clone/npc/walker" : 1,
	]));
        set("no_clean_up", 0);
        set("exits", ([
  		"north" : __DIR__"jiedao2",
  		"south" : __DIR__"dadao",
	]));
        set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
