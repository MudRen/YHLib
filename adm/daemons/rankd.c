// rankd.c

#pragma optimize
#pragma save_binary

#include <ansi.h>

string query_rank(object ob)
{
        mapping fam;

        int shen;
        int budd;
        int tao;
        int exp;
        int age;

        if (ob->is_ghost())
                return HIB "�� ��  �� ��" NOR;

	if (ob->query("rank_info/rank"))
		return HIY "��" + ob->query("rank_info/rank") + "��" NOR;

        shen = ob->query("shen");
        exp  = ob->query("combat_exp");
        age  = ob->query("age");
        fam  = ob->query("family/family_name");
        budd = ob->query_skill("buddhism", 1);
        tao  = ob->query_skill("taoism", 1);

	if (exp > 3000000)
	{
                if (ob->query("gender") == "����")
                        return CYN "�� ��ǧ�� ��" NOR;

                switch (fam)
                {
                case "������":
                        return CYN "�� ʥ  ɮ ��" NOR;
                case "�䵱��":
                        return CYN "�� ��  �� ��" NOR;
                case "������":
                        return CYN "�� ʥ  �� ��" NOR;
                case "��ң��":
                        return CYN "�� ��  �� ��" NOR;
                case "���չ�":
                        return CYN "����ɽ���ѡ�" NOR;
                case "������":
                        return CYN "�������Ϲ֡�" NOR;
                case "��Ĺ��":
                        return CYN "�� ��  �� ��" NOR;
                case "ȫ���":
                        return CYN "�� ����ͨ ��" NOR;
                case "������":
                        return CYN "�� ��  ʥ ��" NOR;
                case "�һ���":
                        return CYN "�� ��  а ��" NOR;
                case "ҩ����":
                        return CYN "������ҩ����" NOR;
                case "Ѫ����":
                        return CYN "��Ѫ�����桿" NOR;
                case "������":
                        return CYN "������������" NOR;
                case "ؤ��":
                        return CYN "�� ��  ؤ ��" NOR;
                case "���ư�":
                        return CYN "�� ��  �� ��" NOR;
                case "��ػ�":
                        return CYN "�� Ӣ  �� ��" NOR;
                case "�컨��":
                        return CYN "������������" NOR;
                case "������":
                        return CYN "������������" NOR;
                case "�嶾��":
                        return CYN "�����ֲ��ġ�" NOR;
                case "����":
                        return CYN "������ʥʹ��" NOR;
                case "÷ׯ":
                        return CYN "�� ׯ  �� ��" NOR;
                case "�����":
                        return CYN "�� ȭ  �� ��" NOR;
                case "������":
                        return CYN "�� ��  �� ��" NOR;
                case "��ڤ��":
                        return CYN "����ڤ���ˡ�" NOR;
                case "������":
                        return CYN "�� ʥ  ɮ ��" NOR;
                case "�����":
                        return CYN "�� ��  а ��" NOR;
                case "��ɽ��":
                        return CYN "�� ��  �� ��" NOR;
                case "��ɽ��":
                        return CYN "�� ��  �� ��" NOR;
                case "��ɽ��":
                        return CYN "�� ��  �� ��" NOR;
                case "̩ɽ��":
                        return CYN "�� ��  �� ��" NOR;
                case "��ɽ����":
                        return CYN "�� ��  ʥ ��" NOR;
                case "��ɽ����":
                        return CYN "�� ��  ħ ��" NOR;
                case "���ǽ���":
                        return CYN "�� ��  а ��" NOR;
                case "������":
                        return CYN "�� ��  �� ��" NOR;
                case "�������":
                        return CYN "������ʥ��" NOR;
                case "������":
                        return CYN "�� ��  ʥ ��" NOR;
                case "ŷ������":
                        return CYN "�� ��  �� ��" NOR;
                case "Ľ������":
                        return CYN "�� ����� ��" NOR;
                case "�������":
                        return CYN "��ѩɽ�ɺ���" NOR;
                case "��ԭ���":
                        return CYN "���������ġ�" NOR;
                case "�̼ұ�":
                        return CYN "�� ��  �� ��" NOR;
                case "���ϻ���":
                        return CYN "�� ��  �� ��" NOR;
                case "ʯ���¼�":
                        return CYN "�� ��  �� ��" NOR;
                case "�����":
                        return CYN "�� ��  �� ��" NOR;
                case "���϶���":
                        return CYN "�� ׯ  �� ��" NOR;
                default:
                        return CYN "�������񻰡�" NOR;
                }
	} else
	if (exp > 2000000)
	{
                if (ob->query("gender") == "����")
                        return HIY "�����ڸ��֡�" NOR;

                switch (fam)
                {
                case "������":
                        return HIY "�� ��  ɮ ��" NOR;
                case "�䵱��":
                        return HIY "�� ��  �� ��" NOR;
                case "������":
                        return HIY "�� ��  �� ��" NOR;
                case "��ң��":
                        return HIY "�� ��  �� ��" NOR;
                case "���չ�":
                        return HIY "��������ʹ��" NOR;
                case "������":
                        return HIY "�� ��ʥ�� ��" NOR;
                case "��Ĺ��":
                        return HIY "�� ��  �� ��" NOR;
                case "ȫ���":
                        return HIY "�� ��  �� ��" NOR;
                case "������":
                        return HIY "�� ��  �� ��" NOR;
                case "�һ���":
                        return HIY "�� ��  а ��" NOR;
                case "ҩ����":
                        return HIY "�� ҩ  ʥ ��" NOR;
                case "Ѫ����":
                        return HIY "�� ��  �� ��" NOR;
                case "������":
                        return HIY "�� ��  �� ��" NOR;
                case "ؤ��":
                        return HIY "�� ��  ؤ ��" NOR;
                case "���ư�":
                        return HIY "�� ̳  �� ��" NOR;
                case "��ػ�":
                        return HIY "�� Ӣ  �� ��" NOR;
                case "�컨��":
                        return HIY "�� Ӣ  �� ��" NOR;
                case "������":
                        return HIY "�������޵С�" NOR;
                case "�嶾��":
                        return HIY "�� ��  �� ��" NOR;
                case "����":
                        return HIY "�� ��  �� ��" NOR;
                case "÷ׯ":
                        return HIY "�� ��  �� ��" NOR;
                case "�����":
                        return HIY "�� ��  �� ��" NOR;
                case "������":
                        return HIY "�����н�����" NOR;
                case "��ڤ��":
                        return HIY "����ڤ������" NOR;
                case "������":
                        return HIY "�� ��  ɮ ��" NOR;
                case "�����":
                        return HIY "�� ��  �� ��" NOR;
                case "��ɽ��":
                        return HIY "�� ��  �� ��" NOR;
                case "��ɽ��":
                        return HIY "�� ��  �� ��" NOR;
                case "��ɽ��":
                        return HIY "�� ��  �� ��" NOR;
                case "̩ɽ��":
                        return HIY "�� ��  �� ��" NOR;
                case "��ɽ����":
                        return HIY "�� ��  �� ��" NOR;
                case "��ɽ����":
                        return HIY "�� ��  �� ��" NOR;
                case "���ǽ���":
                        return HIY "�� ��  �� ��" NOR;
                case "������":
                        return HIY "�� ��  �� ��" NOR;
                case "�������":
                        return HIY "��ʥ�̳��ϡ�" NOR;
                case "������":
                        return HIY "�� ��  �� ��" NOR;
                case "ŷ������":
                        return HIY "�� ��  ħ ��" NOR;
                case "Ľ������":
                        return HIY "�� ��  �� ��" NOR;
                case "�������":
                        return HIY "�� ��  �� ��" NOR;
                case "��ԭ���":
                        return HIY "�� ��  ʥ ��" NOR;
                case "�̼ұ�":
                        return HIY "�� ��  �� ��" NOR;
                case "���ϻ���":
                        return HIY "�� ������ ��" NOR;
                case "ʯ���¼�":
                        return HIY "�� ������ ��" NOR;
                case "�����":
                        return HIY "�� ��  �� ��" NOR;
                case "���϶���":
                        return HIY "�� ŭ�޳� ��" NOR;
                default:
                        return HIY "������̩����" NOR;
                }
	} else
	if (exp > 1000000)
	{
                if (ob->query("gender") == "����")
                        return HIR "�������򻧡�" NOR;

                switch (fam)
                {
                case "������":
                        return HIR "�� ��  �� ��" NOR;
                case "�䵱��":
                        return HIR "�� ��  ʦ ��" NOR;
                case "������":
                        return HIR "�� ��  �� ��" NOR;
                case "��ң��":
                        return HIR "�� ��  ʿ ��" NOR;
                case "���չ�":
                        return HIR "��������ʹ��" NOR;
                case "������":
                        return HIR "�����޶�ʦ��" NOR;
                case "��Ĺ��":
                        return HIR "�� ��  �� ��" NOR;
                case "ȫ���":
                        return HIR "�� ��  ʦ ��" NOR;
                case "������":
                        return HIR "�� ��  �� ��" NOR;
                case "�һ���":
                        return HIR "�� ҩ  �� ��" NOR;
                case "ҩ����":
                        return HIR "�� ҩ  �� ��" NOR;
                case "Ѫ����":
                        return HIR "�� ��  а ��" NOR;
                case "������":
                        return HIR "�� ��  ʦ ��" NOR;
                case "ؤ��":
                        return HIR "�� ��  ؤ ��" NOR;
                case "���ư�":
                        return HIR "�� ��  �� ��" NOR;
                case "��ػ�":
                        return HIR "�� ��  �� ��" NOR;
                case "�컨��":
                        return HIR "�� ��  �� ��" NOR;
                case "������":
                        return HIR "�� ����ʹ ��" NOR;
                case "�嶾��":
                        return HIR "�� ��  �� ��" NOR;
                case "����":
                        return HIR "�� ɢ  �� ��" NOR;
                case "÷ׯ":
                        return HIR "�� ��  ʥ ��" NOR;
                case "�����":
                        return HIR "�� ��  ʦ ��" NOR;
                case "������":
                        return HIR "��ǧ�ֽ�����" NOR;
                case "��ڤ��":
                        return HIR "�����ָ��֡�" NOR;
                case "������":
                        return HIR "�� ��  �� ��" NOR;
                case "�����":
                        return HIR "�� ��  �� ��" NOR;
                case "��ɽ��":
                        return HIR "�� ��  �� ��" NOR;
                case "��ɽ��":
                        return HIR "�� ��  �� ��" NOR;
                case "��ɽ��":
                        return HIR "�� ��  �� ��" NOR;
                case "̩ɽ��":
                        return HIR "�� ��  �� ��" NOR;
                case "��ɽ����":
                        return HIR "�� ��  �� ��" NOR;
                case "��ɽ����":
                        return HIR "�� ��  �� ��" NOR;
                case "���ǽ���":
                        return HIR "�� ��  �� ��" NOR;
                case "������":
                        return HIR "�� ��  �� ��" NOR;
                case "�������":
                        return HIR "�� ��  �� ��" NOR;
                case "������":
                        return HIR "�� ��  �� ��" NOR;
                case "ŷ������":
                        return HIR "�� ��  �� ��" NOR;
                case "Ľ������":
                        return HIR "�� ��  �� ��" NOR;
                case "�������":
                        return HIR "�� ��  �� ��" NOR;
                case "��ԭ���":
                        return HIR "�� ��  �� ��" NOR;
                case "�̼ұ�":
                        return HIR "�� а  �� ��" NOR;
                case "���ϻ���":
                        return HIR "�������ܹܡ�" NOR;
                case "ʯ���¼�":
                        return HIR "�� ��  ͷ ��" NOR;
                case "�����":
                        return HIR "�� ��  Ժ ��" NOR;
                case "���϶���":
                        return HIR "�� ϲ�޳� ��" NOR;
                default:
                        return HIR "�����ֺ��ܡ�" NOR;
                }
	} else
	if (exp > 500000)
	{
                if (ob->query("gender") == "����")
                        return HIG "������ǧ����" NOR;

                switch (fam)
                {
                case "������":
                        return HIG "�� ��  �� ��" NOR;
                case "�䵱��":
                        return HIG "�� ��  �� ��" NOR;
                case "������":
                        return HIG "�� ��  �� ��" NOR;
                case "��ң��":
                        return HIG "�� ��  ʿ ��" NOR;
                case "���չ�":
                        return HIG "�� ��  �� ��" NOR;
                case "������":
                        return HIG "�����޻�����" NOR;
                case "��Ĺ��":
                        return HIG "�� ��  �� ��" NOR;
                case "ȫ���":
                        return HIG "�� ��  �� ��" NOR;
                case "������":
                        return HIG "�� ��  �� ��" NOR;
                case "�һ���":
                        return HIG "�� ������ ��" NOR;
                case "ҩ����":
                        return HIG "�� ҩ  �� ��" NOR;
                case "Ѫ����":
                        return HIG "��ɮ��ͷ�졿" NOR;
                case "������":
                        return HIG "��ɮ��ͷ�졿" NOR;
                case "ؤ��":
                        return HIG "�� ��  ؤ ��" NOR;
                case "���ư�":
                        return HIG "�� ��  �� ��" NOR;
                case "��ػ�":
                        return HIG "�� ��  �� ��" NOR;
                case "�컨��":
                        return HIG "�� ��  �� ��" NOR;
                case "������":
                        return HIG "�� ����ʹ ��" NOR;
                case "�嶾��":
                        return HIG "�� ��  ͽ ��" NOR;
                case "����":
                        return HIG "�� ��  �� ��" NOR;
                case "÷ׯ":
                        return HIG "�� ��  �� ��" NOR;
                case "�����":
                        return HIG "�� ��  �� ��" NOR;
                case "������":
                        return HIG "�� ��  �� ��" NOR;
                case "��ڤ��":
                        return HIG "�� ��  �� ��" NOR;
                case "������":
                        return HIG "�� ��  �� ��" NOR;
                case "�����":
                        return HIG "�� ��  �� ��" NOR;
                case "��ɽ��":
                        return HIG "�� ��  �� ��" NOR;
                case "��ɽ��":
                        return HIG "�� ��  �� ��" NOR;
                case "��ɽ��":
                        return HIG "�� ��  �� ��" NOR;
                case "̩ɽ��":
                        return HIG "�� ��  �� ��" NOR;
                case "��ɽ����":
                        return HIG "�� ��  �� ��" NOR;
                case "��ɽ����":
                        return HIG "�� ��  �� ��" NOR;
                case "���ǽ���":
                        return HIG "�� ��  �� ��" NOR;
                case "������":
                        return HIG "�� ��  �� ��" NOR;
                case "�������":
                        return HIG "�� ��  �� ��" NOR;
                case "������":
                        return HIG "�� ��  ʦ ��" NOR;
                case "ŷ������":
                        return HIG "�� ��  �� ��" NOR;
                case "Ľ������":
                        return HIG "�� ��  �� ��" NOR;
                case "�������":
                        return HIG "�� ��  �� ��" NOR;
                case "��ԭ���":
                        return HIG "�� ��  �� ��" NOR;
                case "�̼ұ�":
                        return HIG "�� ��  �� ��" NOR;
                case "���ϻ���":
                        return HIG "���������졿" NOR;
                case "ʯ���¼�":
                        return HIG "�� ��  �� ��" NOR;
                case "�����":
                        return HIG "�� ��  �� ��" NOR;
                case "���϶���":
                        return HIG "�� ��  �� ��" NOR;
                default:
                        return HIG "�����ָ��֡�" NOR;
                }
	} else
	if (exp > 100000)
	{
                if (ob->query("gender") == "����")
                        return HIC "�������ٻ���" NOR;

                switch (fam)
                {
                case "������":
                        return HIC "�� ��  �� ��" NOR;
                case "�䵱��":
                        return HIC "�� ��  ʿ ��" NOR;
                case "������":
                        return HIC "�� ʦ  ̫ ��" NOR;
                case "��ң��":
                        return HIC "�� ��  ʿ ��" NOR;
                case "���չ�":
                        return HIC "�� ��  Ů ��" NOR;
                case "������":
                        return HIC "�� С���� ��" NOR;
                case "��Ĺ��":
                        return HIC "���������ܡ�" NOR;
                case "ȫ���":
                        return HIC "�� ��  ʿ ��" NOR;
                case "������":
                        return HIC "���������ܡ�" NOR;
                case "�һ���":
                        return HIC "�� ��  �� ��" NOR;
                case "ҩ����":
                        return HIC "�� ��  ʿ ��" NOR;
                case "Ѫ����":
                        return HIC "�� ɮ  �� ��" NOR;
                case "������":
                        return HIC "�� ɮ  �� ��" NOR;
                case "ؤ��":
                        return HIC "�� ��  ؤ ��" NOR;
                case "���ư�":
                        return HIC "�� ��  ͷ ��" NOR;
                case "��ػ�":
                        return HIC "�� ��  �� ��" NOR;
                case "�컨��":
                        return HIC "�� ��  �� ��" NOR;
                case "������":
                        return HIC "�� ����ʹ ��" NOR;
                case "�嶾��":
                        return HIC "�� ��  �� ��" NOR;
                case "����":
                        return HIC "�� ��  �� ��" NOR;
                case "÷ׯ":
                        return HIC "�� ��  Ժ ��" NOR;
                case "�����":
                        return HIC "�� ��  ʿ ��" NOR;
                case "������":
                        return HIC "�� ��  ʿ ��" NOR;
                case "��ڤ��":
                        return HIC "�� ��  ʿ ��" NOR;
                case "������":
                        return HIC "�� ��  �� ��" NOR;
                case "�����":
                        return HIC "�� ��  ʿ ��" NOR;
                case "��ɽ��":
                        return HIC "�� ��  ʿ ��" NOR;
                case "��ɽ��":
                        return HIC "�� ��  ʿ ��" NOR;
                case "��ɽ��":
                        return HIC "�� ��  ʿ ��" NOR;
                case "̩ɽ��":
                        return HIC "�� ��  ʿ ��" NOR;
                case "��ɽ����":
                        return HIC "�� ��  ʿ ��" NOR;
                case "��ɽ����":
                        return HIC "�� ��  ʿ ��" NOR;
                case "���ǽ���":
                        return HIC "�� ��  ʿ ��" NOR;
                case "������":
                        return HIC "�� ��  ʿ ��" NOR;
                case "�������":
                        return HIC "�� ��  �� ��" NOR;
                case "������":
                        return HIC "�� ��  �� ��" NOR;
                case "ŷ������":
                        return HIC "�� ��  Ժ ��" NOR;
                case "Ľ������":
                        return HIC "�� ��  Ժ ��" NOR;
                case "�������":
                        return HIC "�� ��  Ժ ��" NOR;
                case "��ԭ���":
                        return HIC "�� ��  Ժ ��" NOR;
                case "�̼ұ�":
                        return HIC "�� ��  Ժ ��" NOR;
                case "���ϻ���":
                        return HIC "������������" NOR;
                case "ʯ���¼�":
                        return HIC "�� ��  Ժ ��" NOR;
                case "�����":
                        return HIC "�� ��  Ժ ��" NOR;
                case "���϶���":
                        return HIC "�� ��  Ժ ��" NOR;
                default:
                        return HIC "��������ʿ��" NOR;
                }
	} else
	if (exp > 10000)
	{
                if (ob->query("gender") == "����")
                        return YEL "������ʮ����" NOR;

                switch (fam)
                {
                case "������":
                        return YEL "�� ��  ʦ ��" NOR;
                case "�䵱��":
                        return YEL "�� С��ʿ ��" NOR;
                case "������":
                        return YEL "�� ��  �� ��" NOR;
                case "��ң��":
                        return YEL "�� ��  �� ��" NOR;
                case "���չ�":
                        return YEL "�� ��  Ů ��" NOR;
                case "������":
                        return YEL "�� ��  �� ��" NOR;
                case "��Ĺ��":
                        return YEL "���������ˡ�" NOR;
                case "ȫ���":
                        return YEL "�� С��ʿ ��" NOR;
                case "������":
                        return YEL "���������ˡ�" NOR;
                case "�һ���":
                        return YEL "�� ��  �� ��" NOR;
                case "ҩ����":
                        return YEL "�� ҩ  ʦ ��" NOR;
                case "Ѫ����":
                        return YEL "�� ��  �� ��" NOR;
                case "������":
                        return YEL "�� ��  �� ��" NOR;
                case "ؤ��":
                        return YEL "�� ��  ؤ ��" NOR;
                case "���ư�":
                        return YEL "�� ��  �� ��" NOR;
                case "��ػ�":
                        return YEL "�� ��  ʿ ��" NOR;
                case "�컨��":
                        return YEL "�� ��  ʿ ��" NOR;
                case "������":
                        return YEL "�� ����ʹ ��" NOR;
                case "�嶾��":
                        return YEL "�����뽭����" NOR;
                case "����":
                        return YEL "�� ��  ͽ ��" NOR;
                case "÷ׯ":
                        return YEL "�� ��  �� ��" NOR;
                case "�����":
                        return YEL "�� С��ʿ ��" NOR;
                case "������":
                        return YEL "�� ��  ͯ ��" NOR;
                case "��ڤ��":
                        return YEL "�� ��  �� ��" NOR;
                case "������":
                        return YEL "�� ��  ʦ ��" NOR;
                case "�����":
                        return YEL "�� ��  �� ��" NOR;
                case "��ɽ��":
                        return YEL "�� ��  �� ��" NOR;
                case "��ɽ��":
                        return YEL "�� ��  �� ��" NOR;
                case "��ɽ��":
                        return YEL "�� ��  �� ��" NOR;
                case "̩ɽ��":
                        return YEL "�� ��  �� ��" NOR;
                case "��ɽ����":
                        return YEL "�� ��  �� ��" NOR;
                case "��ɽ����":
                        return YEL "�� ��  �� ��" NOR;
                case "���ǽ���":
                        return YEL "�� ��  �� ��" NOR;
                case "������":
                        return YEL "�� ��  �� ��" NOR;
                case "�������":
                        return YEL "�� ��  ͽ ��" NOR;
                case "������":
                        return YEL "�� ��  ʦ ��" NOR;
                case "ŷ������":
                        return YEL "�� ��  �� ��" NOR;
                case "Ľ������":
                        return YEL "�� ��  �� ��" NOR;
                case "�������":
                        return YEL "�� ��  �� ��" NOR;
                case "��ԭ���":
                        return YEL "�� ��  �� ��" NOR;
                case "�̼ұ�":
                        return YEL "�� ��  �� ��" NOR;
                case "���ϻ���":
                        return YEL "�� ��  �� ��" NOR;
                case "ʯ���¼�":
                        return YEL "�� ��  �� ��" NOR;
                case "�����":
                        return YEL "�� ��  �� ��" NOR;
                case "���϶���":
                        return YEL "�� ��  �� ��" NOR;
                default:
                        return YEL "��������ʿ��" NOR;
                }
	} else
	{
                if (ob->query("gender") == "����")
                        return GRN "�� ��  �� ��" NOR;

                switch (fam)
                {
                case "������":
                        return GRN "�� ��  �� ��" NOR;
                case "�䵱��":
                        return GRN "�� ��  ͯ ��" NOR;
                case "������":
                        return GRN "�� С��� ��" NOR;
                case "��ң��":
                        return GRN "�� ѧ  ͯ ��" NOR;
                case "���չ�":
                        return GRN "�� ʹ  Ů ��" NOR;
                case "������":
                        return GRN "�� ��  �� ��" NOR;
                case "��Ĺ��":
                        return GRN "�����뽭����" NOR;
                case "ȫ���":
                        return GRN "�� ��  ͯ ��" NOR;
                case "������":
                        return GRN "�� ��  �� ��" NOR;
                case "�һ���":
                        return GRN "�� ѧ  ͯ ��" NOR;
                case "ҩ����":
                        return GRN "�� ҩ  ͯ ��" NOR;
                case "Ѫ����":
                        return GRN "�� ɳ  �� ��" NOR;
                case "������":
                        return GRN "�� ɳ  �� ��" NOR;
                case "ؤ��":
                        return GRN "�� С�л� ��" NOR;
                case "���ư�":
                        return GRN "�� ��  �� ��" NOR;
                case "��ػ�":
                        return GRN "�� ��  ʿ ��" NOR;
                case "�컨��":
                        return GRN "�� ��  ʿ ��" NOR;
                case "������":
                        return GRN "�� ��  �� ��" NOR;
                case "�嶾��":
                        return GRN "�� ��  �� ��" NOR;
                case "����":
                        return GRN "�� ��  �� ��" NOR;
                case "÷ׯ":
                        return GRN "�� ��  �� ��" NOR;
                case "�����":
                        return GRN "�� ��  ͯ ��" NOR;
                case "������":
                        return GRN "�� ��  ͯ ��" NOR;
                case "��ڤ��":
                        return GRN "�� ��  �� ��" NOR;
                case "������":
                        return GRN "�� ��  �� ��" NOR;
                case "�����":
                        return GRN "�� ��  ͯ ��" NOR;
                case "��ɽ��":
                        return GRN "�� ��  ͯ ��" NOR;
                case "��ɽ��":
                        return GRN "�� ��  ͯ ��" NOR;
                case "��ɽ��":
                        return GRN "�� ��  ͯ ��" NOR;
                case "̩ɽ��":
                        return GRN "�� ��  ͯ ��" NOR;
                case "��ɽ����":
                        return GRN "�� ��  ͯ ��" NOR;
                case "��ɽ����":
                        return GRN "�� ��  ͯ ��" NOR;
                case "���ǽ���":
                        return GRN "�� ��  ͯ ��" NOR;
                case "������":
                        return GRN "�� ��  ͯ ��" NOR;
                case "�������":
                        return GRN "�� ��  �� ��" NOR;
                case "������":
                        return GRN "�� ������ ��" NOR;
                case "ŷ������":
                        return GRN "�� ��  �� ��" NOR;
                case "Ľ������":
                        return GRN "�� ��  �� ��" NOR;
                case "�������":
                        return GRN "�� ��  �� ��" NOR;
                case "��ԭ���":
                        return GRN "�� ��  �� ��" NOR;
                case "�̼ұ�":
                        return GRN "�� ��  �� ��" NOR;
                case "���ϻ���":
                        return GRN "�� ��  �� ��" NOR;
                case "ʯ���¼�":
                        return GRN "�� ��  �� ��" NOR;
                case "�����":
                        return GRN "�� ��  �� ��" NOR;
                case "���϶���":
                        return GRN "�� ��  �� ��" NOR;
                default:
                        return GRN "���������֡�" NOR;
                }
	}
}

string query_respect(object ob)
{
        int age;
        string str;

        if (stringp(str = ob->query("rank_info/respect")))
                return str;

        if ((string)ob->query("id") == "vin")
		return "�������";

        age = ob->query("age");
        switch (ob->query("gender"))
        {
        case "Ů��":
                switch(ob->query("class"))
                {
                case "bonze":
                        if (age < 18) return "Сʦ̫";
                        else return "ʦ̫";
                        break;
                case "taoist":
                        if (age < 18) return "С�ɹ�";
                        else return "�ɹ�";
                        break;
                default:
                        if (age < 18) return "С����";
                        else if (age < 30) return "����";
                        else if (age < 40) return "����";
                        else return "����";
                        break;
                }
        case "����":
        default:
                switch(ob->query("class"))
                {
                case "bonze":
                        if (age < 18) return "Сʦ��";
                        else return "��ʦ";
                        break;
                case "taoist":
                        if (age < 18) return "����";
                        else return "����";
                        break;
                case "scholar":
                        if (age < 18) return "С�๫";
                        else if (age < 50) return "�๫";
                        else return "������";
                        break;
                case "fighter":
                case "swordsman":
                        if (age < 18) return "С�ϵ�";
                        else if (age < 50) return "׳ʿ";
                        else return "��ǰ��";
                        break;
                default:
                        if (age < 20) return "С�ֵ�";
                        else if (age < 50) return "׳ʿ";
                        else return "��ү��";
                        break;
                }
        }
}

string query_rude(object ob)
{
        int age;
        string str;

        if (stringp(str = ob->query("rank_info/rude")))
                return str;

        if ((string)ob->query("id") == "vin")
		return "����ү";

        age = ob->query("age");
        switch (ob->query("gender"))
        {
        case "Ů��":
                switch(ob->query("class"))
                {
                case "bonze":
                        if( age < 18 ) return "С����";
                        if( age < 30 ) return "����";
                        else return "������";
                        break;
                case "taoist":
                        if( age < 18 ) return "С��Ů";
                        if( age < 30 ) return "��Ů";
                        else return "������";
                        break;
                default:
                        if( age < 18 ) return "С��Ƥ";
                        if( age < 25 ) return "С����";
                        if( age < 40 ) return "������";
                        else return "����̫��";
                        break;
                }
        case "����":
        default:
                switch(ob->query("class"))
                {
                case "bonze":
                        if( age < 18 ) return "С��ͺ";
                        if( age < 50 ) return "��ͺ¿";
                        else return "��ͺ¿";
                        break;
                case "taoist":
                        if( age < 18 ) return "С��ë";
                        if( age < 30 ) return "��ţ����";
                        else return "����ë";
                        break;
                case "scholar":
                        if( age < 18 ) return "С�����";
                        else if( age < 50 ) return "�������";
                        else return "��ͯ��";
                        break;
                default:
                        if (age < 18) return "С������";
                        if (age < 20) return "С���˵�";
                        if (age < 30) return "ֱ����";
                        if (age < 50) return "����";
                        if (age < 80) return "��ƥ��";
                        else return "�ϲ���";
                        break;
                }
        }
}

string query_self(object ob)
{
        int age;
        string str;

        if (stringp(str = ob->query("rank_info/self")))
                return str;

        if ((string)ob->query("id") == "vin")
		return "��";

        age = ob->query("age");
        switch (ob->query("gender"))
        {
        case "Ů��":
                switch(ob->query("class"))
                {
                case "bonze":
                        if( age < 50 ) return "ƶ��";
                        else return "����";
                        break;
                case "taoist":
                        return "ƶ��";
                        break;
                default:
                        if( age < 20 ) return "СŮ��";
                        if( age > 50 ) return "����";
                        else return "���";
                        break;
                }
        case "����":
        default:
                switch(ob->query("class"))
                {
                case "bonze":
                        if( age < 18 ) return "С��";
                        if( age < 40 ) return "ƶɮ";
                        else return "����";
                        break;
                case "taoist":
                        if( age < 18 ) return "С��";
                        if( age < 30 ) return "ƶ��";
                        else return "�ϵ�";
                        break;
                case "scholar":
                        if( age < 30 ) return "����";
                        else return "����";
                        break;
                default:
                        if( age < 50 ) return "����";
                        else return "��ͷ��";
                        break;
                }
        }
}

string query_self_rude(object ob)
{
        int age;
        string str;

        if (stringp(str = ob->query("rank_info/self_rude")))
                return str;

        if ((string)ob->query("id") == "vin")
		return "����";

        age = ob->query("age");
        switch(ob->query("gender"))
        {
        case "Ů��":
                switch(ob->query("class"))
                {
                case "bonze":
                        if( age < 50 ) return "ƶ��";
                        else return "����";
                        break;
                case "taoist":
                        return "���ɹ�";
                        break;
                default:
                        if( age < 20 ) return "������";
                        if( age < 30 ) return "��������";
                        else return "����";
                        break;
                }
        case "����":
        default:
                switch(ob->query("class"))
                {
                case "bonze":
                        if( age < 50 ) return "�������";
                        else return "�Ϻ�����";
                        break;
                case "taoist":
                        if( age < 30 ) return "��ɽ��";
                        return "�ϵ���";
                        break;
                case "scholar":
                        if( age < 50 ) return "���๫";
                        else return "�Ϸ�����";
                        break;
                default:
                        if( age < 20 ) return "����ү��";
                        if( age < 40 ) return "��ү��";
                        else return "����";
                        break;
                }
        }
}

varargs string query_close(mixed ob, int a1, int a2)
{
        if (! a1 && this_player())
                a1 = this_player()->query("age");

        if (! a2 && objectp(ob))
                a2 = ob->query("age");

        switch (objectp(ob) ? ob->query("gender") : ob)
        {
        case "Ů��":
                if (a1 >= a2)
                        return "����";
                else
                        return "���";
                break;

        default:
                if (a1 >= a2)
                        return "�ܵ�";
                else
                        return "���";
        }
}

varargs string query_self_close(mixed ob, mixed me, int a1, int a2)
{
        if (! a1 && this_player())
                a1 = this_player()->query("age");

        if (! a2 && objectp(ob))
                a2 = ob->query("age");

        switch (objectp(me) ? me->query("gender") :
                this_player() ? this_player()->query("gender") : me)
        {
        case "Ů��" :
                if (a1 >= a2)
                        return "�����";
                else
                        return "С����";
                break;

        default :
                if (a1 >= a2)
                        return "������";
                else
                        return "С����";
        }
}

