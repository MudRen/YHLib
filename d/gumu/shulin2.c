
inherit ROOM;

void create()
{
        set("short", "С����");
        set("long", @LONG
������һ���ּ��С���ϣ����ܶ�������Զ���ƺ���һ��
�����ķ��ܴ�������¶�˳�����Ҳ������ɽ����һ������֮
�ࡣ��Щ����󶼽в��������������䶼�Ѿ��ܳ��ˡ�
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "southwest" : __DIR__"shulin3",
                "northeast" : __DIR__"shulin1",
        ]));

        setup();
        replace_program(ROOM);
}

