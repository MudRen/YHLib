#include <ansi.h>; 
inherit ITEM;
// ���¾Ž�֮���н������
// Edit by Rcwiz for Hero

void create()
{
        set_name(HIW "�����¾Ž��б���" NOR, ({ "dugu canben", "dugu", "canben" }));
        set_weight(500);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("material", "paper");
                set("no_sell", 1);
                set("long", HIW "\n����һ���ñ�ֽд�ɵ��飬��Ƥ��д�С����¾Ž�\n"
                                  "�б������֡���Ƥ���ƣ������Ѿ�����ܾ��ˡ���\n"
                                  "�м����˽�ħ��������������¾Ž�֮���衣\n"
                                  "����ͼ����������ص����ݣ�������ֻ���������\n"
                                  "�ȣ����޶�����ܱ��˽��⣬����Զ�޷���͸�ġ�\n");
        }
}

