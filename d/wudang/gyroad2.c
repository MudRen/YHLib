inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "��԰");
        set("long", @LONG
�����ɵ��߽���԰��԰����Ӣ�ͷף������������֣�ʢ��
�ŷۺ���һ�������һƬ���������ߡ��м�ȴ��һ��ڸ���Ķ
�Ĵ���(tree)����ס����ô�һƬ����
LONG);
        set("outdoors", "wudang");
        set("item_desc", ([
                "tree" : GRN "\n����һ���˲ι�������˵ժ���˲ι����˶�"
                         "�书������кô���\n\n" NOR
        ]));
        set("exits", ([
                "west" : __DIR__"gyroad1",
        ]));
        set("guocount",1);
        setup();
}

void init()
{
        add_action("do_zhai", "zhai");
}

int do_zhai(string arg)
{
        object guo, me = this_player();

        if (! arg || arg == "")
                return notify_fail("����ժʲô��\n");

        if (arg == "guo" || arg == "renshen guo")
        {
                if (uptime() < 1800)
                {
                        message_vision(HIY "$N" HIY "���˿��˲ι���������"
                                       "���ϵĹ��Ӷ�δ���죬����ʧ����̾��"
                                       "������\n", me);
                        return 1;
                } else
                if (query("guocount") > 0 && random(10) == 1)
                {
                        message_vision(HIC "\n$N" HIC "���˲ι�����ժ��һ"
                                       "����͸��" HIM "�˲ι�" HIC "������"
                                       "��ϲ������\n\n" NOR, me);
                        guo = new(__DIR__"obj/renshenguo");
                        guo->move(me, 1);
                        add("guocount", -1);
                        return 1;
                } else
                {
                        set("guocount", 0);
                        message_vision(HIY "$N" HIY "���˿��˲ι���������"
                                       "������֦Ҷ���иձ���ժ���ĺۼ���\n", me);
                        return 1;            
                }
        }
        return 0;
}
