inherit ROOM;

void create()
{
        set("short", "����С��");
        set("long", @LONG
������������ǵļ�����ڡ������ǵļ���ר��������Ѻ��
���Ź�ĵ��ӣ�һЩ���е����鷸�ƣ���������֮ͽҲ˳����Ѻ
�ڴˡ���������һ�����ɣ������Ź�ɭ�ϣ���Ҳ���з����ߣ���
�����������صأ�������Ҳ���ܡ�
LONG );
        set("exits", ([
                "west" : __DIR__"iceroad3",
                "down" : __DIR__"laolang",
        ]));
        set("objects", ([ 
                __DIR__"npc/yan" : 1,
                __DIR__"npc/dizi" : 3,
        ])); 
        setup(); 
}

int valid_leave(object me, string dir)
{
        object yan;

        if (dir != "down" ||
            ! objectp(yan = present("yan wanpeng", this_object())))
                return ::valid_leave(me, dir);

        return yan->permit_pass(me, dir);
}
