inherit ROOM;

void create()
{
        set("short", "Сԡ��");
        set("long", @LONG
��ЩСԡ�Ҿ���ר��װ�ޣ�������ר���ź��ɨ�����Ժ�
�ɾ���ǽ�����л��������ʻ��������Ϲ�����С���񡣷�����
�е�Ȼ��ԡ�裬��Щ��Ϊʾ�Է���ģ��ݷ�֮ǰ��Ҫ��ԡ��
LONG);
        set("objects", ([
                __DIR__"npc/obj/zaopeng" : 1,
        ]));
        set("exits", ([
                "east" : __DIR__"yushi",
        ]));

        setup();
        replace_program(ROOM);
}
