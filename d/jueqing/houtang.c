inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����Ⱥ��ðڷ��Ÿ�������ĹŶ����մɣ����п�ǽ����
�����Ϲ���һ�������������������ƣ�����Ǿ���ȿ�ɽ��
ʦ����λ��
LONG);
        set("exits", ([
               "west"   : __DIR__"zhifang",
               "north"   : __DIR__"jianshi",
               "east"   : __DIR__"chucangshi",
               "south"   : __DIR__"changlang4",
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

