inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���������ư��ڵĳ��������������һ����¯�����ռȥ��һ����
���䡣�������кܶ���ۣ���ͬʱ���ܶ��ֲˡ���λ���еĳ�����������æ
µ�š��������������Ÿ��ַ��˵���ζ���������˴������Ρ�
LONG    );
        set("exits", ([
                "south" : __DIR__"zoulang-3",
        ]));

        set("objects", ([ 
                __DIR__"obj/hsnr" : 2,
                __DIR__"obj/ruzhu" : 1,
                __DIR__"obj/fan" : 2,
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
