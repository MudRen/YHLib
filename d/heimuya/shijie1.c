inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�н����ˣ�ɽ·ͻȻ���ͣ�����ɽ��������м�����һ��
խխ��ʯ�ף��������˲�����С�
LONG);
        set("outdoors", "heimuya");
        set("exits", ([
            	"eastdown" : __DIR__"shandao2",
            	"westup"   : __DIR__"shijie2",
        ]));
        set("objects", ([
                CLASS_D("riyue") + "/yun" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
