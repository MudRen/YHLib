inherit ROOM;

void create()
{
        set("short", "���᷿");
        set("long", @long
���᷿ԭ�Ƕ�ׯ�������ҵ����ڣ����ʼ�����һӦ���֮���뱸������
�����ǿ�����        
long );
        set("exits", ([
                "east"    : __DIR__"zoulang5",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}