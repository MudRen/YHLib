inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣�
�������ƣ��������ش�졣һֱ������Զ���Ǻ�ɽ��������
��ף�ڷ��ˡ� 
LONG
);
        set("exits", ([ 
                "eastdown" : __DIR__"zhurongdian",
                "westup"   : __DIR__"shanlu004",         
        ]));

        set("outdoors", "henshan");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

