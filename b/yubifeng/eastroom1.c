inherit ROOM;

void create()
{
        set("short", "���᷿");
        set("long", @long
���᷿ԭ�Ƕ�ׯ��������͵����ڣ����ʡ����硢������һӦ���֮��
�뱸����������ǿ�����        
long );
        set("exits", ([
                "west"    : __DIR__"zoulang4",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}