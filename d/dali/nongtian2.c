inherit ROOM;

void create()
{
        set("short", "ũ��");
        set("long", @LONG
����һС����ͨ��ˮ��أ���گ��ů��ʪ���Թ���������
��ֲˮ��Ϊ�����⸽���Ǵ�������ټ���ƽԭ���Σ���Ҫ�Ը�
��Ϊ���İ����˿�����һЩ��ũ���ػ��ֳ�С�飬һЩ��
������������������ˮţ�������е�·����ũ���򶫶�ȥ��
LONG);
        set("objects", ([
                __DIR__"npc/nongfu2": 1,
        ]));
        set("outdoors", "dali");
        set("exits", ([
                "west"   : __DIR__"luojiadian",
                "east"   : __DIR__"nongtian3",
                "south"  : __DIR__"langan1",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
