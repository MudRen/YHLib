inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�н����ˣ�ɽ·ͻȻ���ͣ�����ɽ��������м�����һ��
խխ��ʯ�ף������������˲�����С�����������������Լ��
��һ��ʯ�š�
LONG);
        set("outdoors", "heimuya");
        set("exits", ([
            	"eastdown" : __DIR__"shijie1",
            	"westup"   : __DIR__"shimen",
        ]));
        set("objects", ([
                CLASS_D("riyue") + "/fan" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
