inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����ǵ�ɽʯ�׵ľ�ͷ�����ţ��������߾����䵱�����ˡ�
LONG);
        set("exits", ([
                "northdown": __DIR__"ertiangate",
                "southup"  : __DIR__"jinding",
        ]));
        set("outdoors", "wudang");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
