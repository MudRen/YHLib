inherit ROOM;

void create()
{
        set("short", "�չ��Ҵ���");
        set("long", @LONG
���Ǳչ����ϱߣ�������һ�ȴ��ű���ͨ���չ��ҡ�����
������ɽͯ�ѱչ������ĵط�������ɽͯ����ȥ֮��������
�㽫�˴�Ų������÷������Ľ��þ�ס��
LONG);
        set("outdoors", "lingjiu");
        set("exits", ([
                "north" : __DIR__"biguan",
                "south" : __DIR__"xiaodao2",
        ]));
        set("objects",([
                CLASS_D("lingjiu") + "/shisao" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
