inherit ROOM;

void create()
{
        set("short", "ɽ�¸ʻ��");
        set("long", @LONG
ɽ�¸ʻ����ɽ��������������ĸ��̾޼ֽ���ģ�����
��ͬ��ۻ�ĳ��������Ǹ������ص��˾ۻ�ġ���ȻҲ���ڴ�
����̸����ġ�������ǹص���
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"west" : __DIR__"eroad2",
  		"east" : __DIR__"paifang",
	]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
        set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
