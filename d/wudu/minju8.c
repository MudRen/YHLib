inherit ROOM;

void create()
{
        set("short", "�");
        set("long", @LONG
����һ����ª������ıڶ����̻�Ѭ�ĺں����ģ���̨�Ե�ǽ
������һ�ŷ��ƵĻ���ֽ���Ա߹���һЩ��ɵ����⡣��̨�����Ե�
ˮ���ϰ��ż�ֻ�ִɴ��룬�ݵ�һ�Ƕ���һ�����ա� 
LONG);

        set("exits", ([
                "east" : __DIR__"minju3",
        ]));
        set("objects", ([
                  __DIR__"obj/qhcwan": 2,
                  __DIR__"obj/shourou2": 1,
                  __DIR__"obj/shourou1": 1,
        ]));
        setup();
        replace_program(ROOM);
}
