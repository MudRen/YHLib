inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long", @LONG
������һ���ľ�����԰���߸ߵ͵͵Ĵ��������װ��ñ�
�����¡��������Ǻ�Ժ���������и���Է���ϱ��ǻ�԰��
LONG);
        set("exits",([
                "northeast" : __DIR__"sheyuan",
                "northwest" : __DIR__"houyuan",
                "south"     : __DIR__"huayuan",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "baituo");
        setup();
        replace_program(ROOM);
}
