inherit ROOM;

void create()
{
        set("short", "��կ����");
        set("long", @LONG
���������置�ؽ磬ֻ����ɽ��ˮ�㣬�羰����ԭ����ͬ����
����·�ϣ���ʱ������������Ů��·����Ұ���ظ����裬��ʱֻ����
���泩����Ը���ϴ��硣������һ����ˮ��סȥ·��
LONG);
        set("outdoors", "wudujiao");

        set("exits", ([
                "east" : __DIR__"jiang1",
                "northeast" : __DIR__"bianzhai1",
                "north" : __DIR__"bianzhai2",
        ]));

        setup();
}
