inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����Ϻ�ɽ���֮һ�������壬����Ⱥɽ��������У�ÿ
ÿ������ʪʱ������������������������ˡ���ɽ�ɾ�ѧ��
���������Ǵ�����������ġ�
LONG);
        set("exits", ([ 
                "westdown"   : __DIR__"shanlu10",
                "eastdown"   : __DIR__"shanlu7",
        ]));

        set("objects", ([
                CLASS_D("henshan") + "/lu" : 1,
        ]));    

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

