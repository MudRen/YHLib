#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�߲����");
        set("long", @LONG
�����Ǹ߲��Թ��ĺ��������м��߰׹�����ֻ�����
������Ȼ���ݣ������ж����˻�ɳ���������ƺ�����·������
����վ��һ�����õ�ס��ȥ·��
LONG);
        set("exits", ([
                "south" : __DIR__"zoulang2",
                "north" : __DIR__"mishi2"
        ]));
        setup();
}

void init()
{
        object ob, room;
        ob = this_player();
        room = this_object();

        if (present("map", ob))
        {
                message_vision(HIY "\nͻȻ֮�䣬ֻ��ǰ��һ����ɭɭ��������Ц��������Ȼ���е�\n"
                               "֮ʿ����ô���и߲��Թ��ĵ�ͼ���ѵ������⣿�߲��Թ����\n"
                               "�ей��ĲƸ��𣿹���������������������������Ц����͸��\n"
                               "���޵������ͱ�״��\n\n" NOR, ob);
        } else
        {
        	message_vision(HIR "\nͻȻ֮�䣬ֻ��ǰ��һ����ɭɭ��������ȵ������ô��߲���\n"
                               "������������ʱֻ��һ�������Ϯ���������Ҳ�㲻���ˡ�ԭ\n"
                               "����һ���������������塣\n\n" NOR, ob);
                ob->set_temp("die_reason", "������������");
        	ob->die();
        }

}
