inherit ROOM;

void create()
{
        set("short", "�������");
        set("long", @LONG
���������רΪ�������������������ġ����ڽ�����ʦ��
ʮ��Ϊ�˲��ݵģ�����������������ڴ�ѧϰһЩ�����ķ���
�书��һ�������ù�����ȣ�����Ҳ��Ϊ���ѡ��һ����Ľ��
���ɡ�ǽ�����Ÿ����ӡ�
LONG);
        set("objects", ([
                __DIR__"npc/chen" : 1,
        ]));
        set("no_fight", 1);
        set("no_steal", 1);
        set("no_beg", 1);
        set("exits", ([
                "north"     : __DIR__"xidajie2",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


