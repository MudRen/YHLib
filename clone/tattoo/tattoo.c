#include <ansi.h>
inherit ITEM;

string long();

void create()
{
        set_name(NOR + WHT "����ͼ" NOR, ({ "tattoo paper", "tattoo", "paper" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�Źžɵ�ͼƬ���������Щ������");
                set("unit", "��");
                set("material", "paper");
                set("value", 500);                        // ����ʱ�Ļ�����ͼ�ڵļ�ֵ���
                set("tattoo_long", "���ұ����ĸ�����");   // �����ò�λ������
                set("can_tattoo", ({ "����", "�ؿ�",
                                     "��", "���",
                                     "�ұ�", "�β�", })); // �����ܹ����ܴ���Ĳ�λ
                set("tattoo_type", ({ "����", "����",     // ���Ӻ������Ե����࣬��������
                                      "����", "��",     // ��Ŀ�Ľ���������ܹ�������
                                      "��ò", }));
                set("tattoo_str", 1);                     // ��Ӧ����ĺ����������࣬����
                set("tattoo_int", 1);                     // ��Ӧ�ļǺš�
                set("tattoo_con", 1);
                set("tattoo_dex", 1);
                set("tattoo_per", 1);
                set("tattoo_special", "power");           // ����ʱ���ӵ����⼼��
                set("tattoo_spcname", "������");        // ��lookʱ���ṩ����ʾ��Ϣ
        }
}

string long()
{
        string msg;

        if (query("can_tattoo"))
        {
                msg = WHT "����һ��" + name() + NOR + WHT "��ͼ������" + query("tattoo_long") + "�������"
                      "������ʦ��������ͼ�������" + implode(query("can_tattoo"),
                      "��") + "�ϴ��࣬��������" + implode(query("tattoo_type"),
                      "��") + "��";

                if (query("tattoo_special"))
		{
                        msg += "���⣬" + name() + NOR + WHT "���ܴ�"
                               "����" + query("tattoo_spcname") + NOR
                               WHT "������������";
		} else
		{
                        msg += "���⣬" + name() + NOR + WHT "�ƺ���"
                               "�̲���ĳЩδ֪������������";
		}
        } else
                msg = "����һ�Źžɵ�ͼƬ���������Щ������";

        return sort_string(msg, 54);
}

int query_autoload()
{
        return 1;
}

