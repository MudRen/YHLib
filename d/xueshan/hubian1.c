inherit ROOM;

void create()
{
        set("short", "����С·");
        set("long", @LONG
����ʥ���ߵ�С·��·��ĺ�ˮ��Ϊ�峺��������ӳ�Ű�
��ѩɽ�Գ�һƬ�����ĵ�������������Χȴ�Ǳ���Ũ��������
���֣�ʹ�����ǰһƬ���ʣ��Ʋ������ܡ�
LONG );
        set("outdoors", "xuedao");
        set("exits", ([
                "west" : __DIR__"shenghu",
                "east" : __DIR__"hubian2",
        ]));
        setup();
}
