#include <ansi.h>
inherit ROOM;

string look_gaoshi();

void create()
{
        set("short", "���ݶ���");
        set("long", @LONG
�������ݳǵĶ����ţ���������Ļ���������������
��ɳ��ʴ�Ե���Щ�ưܡ��������Ϸ�����ǿǿ�����ϳ�������
�����֣���ǽ�����ż���ͨ����ʾ(gaoshi)��������߽�����
�����ﷸ�������������ӻ���ԭ���ٱ��ǽ䱸ɭ�ϣ���������
��ס���˽������ʡ�һ����ֱ����ʯ��������������졣��
���ǽ��⣬��������������˶��Ǵ�������ǣ��򶫵�����ԭ��
��౾����Ҳ�������ڴ����ﾭ����������ȥ�����Լ��ֵĹ�
����������������Ʒ�������ǳ��
LONG);
        set("outdoors", "lanzhou");
        set("item_desc", ([
                "gaoshi" : (: look_gaoshi :),
        ]));

        set("exits", ([
                "west" : __DIR__"dongdajie1",
                "east" : "/d/changan/lzroad",
                
        ]));
        set("objects", ([
                "/d/city/npc/bing" : 4,
                "/clone/npc/xunbu" : 1,
                "/d/beijing/npc/ducha" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n         ����֪��\n                     Ү��Ѳ\n";
}

