
inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
������Զ��������һ��С�ݣ�������ʰ���������һ����
Ⱦ�����������ͨ�˼�һ�㣬��ľ�����Σ�ϸ�ŵı���������
�Ĵ󴲡����ֱ���󲻵�������Ĺ�Ĺ֮�л�����Ȱ��衣
LONG
        );

        set("exits", ([
                "west" : __DIR__"xiaowu2",
        ]));

        set("objects", ([
                __DIR__"obj/ping" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
