inherit ROOM;
string* objs = ({
        __DIR__"obj/fugu",
        __DIR__"obj/chuanxin",
        __DIR__"obj/shexinzi",
        __DIR__"obj/fugu",
        __DIR__"obj/chuanxin",
        __DIR__"obj/shexinzi",
        __DIR__"obj/qianrizui",
});

void create()
{
        set("short", "ҩ��");
        set("long", @LONG
�������嶾�̴��ҩƷ�ĵط�����ֻ��ʮ�������ľ��һ���ſ���
���濪�����ٸ���С���룬ÿ���������涼�������������һ�б�ǩ��
�������Ÿ������ҩ�ģ����д�������ж��ġ��Ա�һ�����Ϸ���
�����ղ����Ĳ�ҩ�� 
LONG);
        set("exits", ([
                "west" : __DIR__"nanyuan",
        ]));
        set("objects", ([
                objs[random(sizeof(objs))] : 1,
                objs[random(sizeof(objs))] : 1,
                __DIR__"obj/zhulou"        : 2,
        ]));

        setup();
        replace_program(ROOM);
}
